#include "Broke.h"

Broke::Broke(const string &name, const string &description)
        : Status(BROKE),
          name(name),
          description(description) {}

Broke::~Broke() {

}

vector<string> Broke::getData() {
    vector<string> brokeData = {name, description};
    return brokeData;
}

vector<string> Broke::getStatusPrintData(bool shortVersion) {
    vector<string> brokeData;

    brokeData.push_back("type: " + getStatusTypeName());
    brokeData.push_back("name: " + name);
    brokeData.push_back("description: " + description);

    return brokeData;
}
