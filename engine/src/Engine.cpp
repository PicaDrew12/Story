#include<iostream>
#include "Engine.h"


Engine::Engine() {
	
}

void Engine::Start() {
	
	startingNode->Run();
}

void Engine::SetStartingNode(const std::shared_ptr<Node>& node) {
	startingNode = node;
}

void Engine::LoadMetadata() {
	if (fileExplorer.IsGameDirectory(gameDirectory)) {
		printer.print("Is valid game directory");
		std::ifstream metadata(gameDirectory / "metadata");
		std::string line;
		std::string tmp;
		for (int i = 0; i < 3; i++) {
			std::getline(metadata, line);
			std::istringstream iss(line);
			if (i == 0) {

				iss >> tmp >> gameMetadata.projectName;
			}
			if (i == 1) {
				iss >> tmp >> gameMetadata.projectVersion;
			}if (i == 2) {
				iss >> tmp >> gameMetadata.projectAuthor;
			}
		}
	}
	printer.print("Found project metadata:", gameMetadata.projectAuthor, " ", gameMetadata.projectName, " ", "", gameMetadata.projectVersion);
}

void Engine::ReadChrFile(fs::path path){
	std::ifstream chr(path);
	std::string line;
  Character newChar;

  while( std::getline(chr, line)){
    std::istringstream iss(line);
    std::string key;
    std::string  value;
        if(iss>>key>>value){
      if(key == "character_name"){
        
        newChar.name = value;
      }
      if(key== "character_color_accent"){
        newChar.colorAccent = value;
      }
    }

  }
  characters[newChar.name] = newChar;

}

void Engine::LoadCharacterData() {
  for(const auto& entry: fs::recursive_directory_iterator(gameDirectory/"characters")){
    if(entry.path().extension().string()==".chr"){
      ReadChrFile(entry.path());
    }
  }
  for( auto& cha : characters){
    printer.print(cha.second.name," ", cha.second.colorAccent,"\n");
  }
}

void Engine::OpenProject(fs::path pathToProject) {
	gameDirectory = pathToProject;
	LoadMetadata();
  LoadCharacterData();
}
