#include "ChoiceNode.h"

void ChoiceNode::Run() {
	printer.printSpeed = 20;
	printer.Format("yellow");
	printer.typeWriterPrint(question);
	std::vector<std::shared_ptr<Node>> choiceList;
	int index = 1;
	for (auto& element : choices) {
		printer.SetRandomColor();
		printer.typeWriterPrint(index,". ",element.first);
		choiceList.push_back(element.second);
		index++;
	}
	printer.ResetFormat();
	printer.typeWriterPrintN("Choose: ");
	std::cin >> index;
	printer.print();
	
	choiceList[index - 1]->Run();
}