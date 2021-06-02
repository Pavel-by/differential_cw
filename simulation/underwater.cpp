#include "underwater.h"
#include <assert.h>

Underwater::Underwater()
{
    materials = {
        &MaterialConfig::iceberg,
        &MaterialConfig::icebergBack,
    };
}

Underwater::~Underwater() {
    detachIceberg();
}

void Underwater::attachIceberg(Iceberg* iceberg) {
    assert(_iceberg == nullptr);
    _iceberg = iceberg;
    QObject::connect(_iceberg, SIGNAL(changed()), this, SLOT(icebergChanged));
}

void Underwater::detachIceberg() {
    assert(_iceberg != nullptr);
    QObject::disconnect(_iceberg, SIGNAL(changed()), this, SLOT(icebergChanged));
    _iceberg = nullptr;
}

void Underwater::icebergChanged() {
    markNeedsPaint();
}
