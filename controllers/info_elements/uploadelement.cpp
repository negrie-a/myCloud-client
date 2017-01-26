#include "uploadelement.h"

UploadElement::UploadElement(QString pathFile, QString name, QString pathClient, QString pathServer, Status status, quint64 size, quint64 id, quint64 octetAlreadyTransfered) :
    InfoElement(pathFile, name, pathClient, pathServer, status, size, id)
{
    _transfertType = TransfertType::UPLOAD;

    if (isFinish()) { // If all data has been send
        _status = Status::FINISH;
    }

    _sizeTransfered = octetAlreadyTransfered;

    if (!isFinish()) {
        if (!this->open(QIODevice::ReadOnly)) { // Try to open client file
            _status = Status::ERROR_CLIENT_PATH;
        }
        else {
            _status = status;
            this->read(octetAlreadyTransfered);
            this->start();
        }
    }
}

int UploadElement::getProgression()
{
    if (_sizeTransfered > _sizeServer)
        _sizeTransfered = _sizeServer;
    return (float)_sizeTransfered / (float)_sizeServer * 100;
}

bool UploadElement::isFinish() {
    return _sizeTransfered >= _sizeServer;
}

void UploadElement::setOctetsTransfered(int nbOctet)
{
    _sizeTransfered += nbOctet;
}

quint64 UploadElement::getSizeTransfering() {
    return _sizeTransfered;
}
