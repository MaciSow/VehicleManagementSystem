#include "Status.h"

Status::Status(StatusType statusType) : statusType(statusType) {}

void Status::log() {
    if (statusType == AVAILABLE) {
        cout << "available" << endl;
        return;
    }
    if (statusType == ROAD) {
        cout << "road" << endl;
        return;
    }
    if (statusType == REPAIR) {
        cout << "repair" << endl;
        return;
    }
    if (statusType == BROKE) {
        cout << "broke" << endl;
        return;
    }

    cout << "error" << endl;
}

StatusType Status::getStatusType() const {
    return statusType;
}

string Status::getStatusName() {
    switch (statusType) {
        case AVAILABLE:
            return "Available";

        case ROAD:
            return "On the road";

        case BROKE:
            return "Broke down";

        case REPAIR:
            return "In repair";

        default:
            return "Unknown";
    }
}

string Status::getStatusTypeName() {
    switch (statusType) {
        case AVAILABLE:
            return "Available";

        case ROAD:
            return "Road";

        case BROKE:
            return "Broke";

        case REPAIR:
            return "Repair";

        default:
            return "Available";
    }
}

vector<string> Status::getData() {
    return vector<string>();
}

vector<string> Status::getStatusPrintData(bool shortVersion) {
    vector<string> statusData = {"type: " + getStatusTypeName()};
    return statusData;
}
