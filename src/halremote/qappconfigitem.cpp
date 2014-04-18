#include "qappconfigitem.h"

QAppConfigItem::QAppConfigItem(QQuickItem *parent) :
    QQuickItem(parent)
{
    m_name = "";
    m_description = "";
    m_type = QT5_QML;
    m_webUri = "";
    m_loaded = false;
    m_mainFile = "";
}