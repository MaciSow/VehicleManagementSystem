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
