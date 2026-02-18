#pragma once 
#include "Node.h"
#include "DialogueNode.h"
#include "EndNode.h"
#include "JumpNode.h"
#include "ChoiceNode.h"
#include<unordered_map>
#include<memory>
#include<vector>
#include<filesystem>
#include "../../filesystem/include/FileExplorer.h"
#include<fstream>
#include<sstream>

namespace fs = std::filesystem;

struct GameMetadata {
    std::string  projectName;
    std::string  projectAuthor;
    float projectVersion;


};

struct Character {
    std::string name;
    std::string colorAccent;
};

struct Label{
  std::string name;
  std::vector<std::shared_ptr<Node>> labelNodes;
};


 class Engine {
  public:
    std::unordered_map<std::string, Label> labels;
    fs::path gameDirectory;
    GameMetadata gameMetadata;
    std::unordered_map<std::string, Character> characters;

    std::shared_ptr<Node> startingNode;
    std::vector<std::shared_ptr<Node>> nodes;
    Engine();
    void Start();
    void SetStartingNode(const std::shared_ptr<Node>& node);
    void OpenProject(fs::path pathToProject);
    void LoadCharacterData();
    void LoadMetadata();
    void ReadChrFile(fs::path path);
    void LoadSceneData();
    void ReadSceneFile(fs::path path);


};
