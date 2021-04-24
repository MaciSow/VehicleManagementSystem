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
