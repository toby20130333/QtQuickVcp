/****************************************************************************
**
** Copyright (C) 2014 Alexander Rössler
** License: LGPL version 2.1
**
** This file is part of QtQuickVcp.
**
** All rights reserved. This program and the accompanying materials
** are made available under the terms of the GNU Lesser General Public License
** (LGPL) version 2.1 which accompanies this distribution, and is available at
** http://www.gnu.org/licenses/lgpl-2.1.html
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** Lesser General Public License for more details.
**
** Contributors:
** Alexander Rössler @ The Cool Tool GmbH <mail DOT aroessler AT gmail DOT com>
**
****************************************************************************/
#ifndef QAPPDISCOVERY_H
#define QAPPDISCOVERY_H

#include <QObject>
#include <QQmlParserStatus>
#include <qjdns.h>
#include <qjdnsshared.h>
#include "qservicediscoveryitem.h"
#include "qservice.h"
#include "qservicelist.h"
#include "qservicediscoveryfilter.h"
#include "qnameserver.h"

class QServiceDiscovery : public QObject, public QQmlParserStatus
{
    Q_OBJECT
    Q_INTERFACES(QQmlParserStatus)
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(bool networkReady READ isNetworkReady NOTIFY networkReadyChanged)
    Q_PROPERTY(bool lookupReady READ isLookupReady NOTIFY lookupReadyChanged)
    Q_PROPERTY(QServiceDiscoveryFilter *filter READ filter WRITE setFilter NOTIFY filterChanged)
    Q_PROPERTY(QQmlListProperty<QServiceList> serviceLists READ serviceLists)
    Q_PROPERTY(LookupMode lookupMode READ lookupMode WRITE setLookupMode NOTIFY lookupModeChanged)
    Q_PROPERTY(int unicastLookupInterval READ unicastLookupInterval WRITE setUnicastLookupInterval NOTIFY unicastLookupIntervalChanged)
    Q_PROPERTY(QQmlListProperty<QNameServer> nameServers READ nameServers NOTIFY nameServersChanged)

    Q_ENUMS(LookupMode)

public:
    enum LookupMode{
        MulticastDNS,
        UnicastDNS
    };

    explicit QServiceDiscovery(QObject *parent = 0);

    void classBegin() {}
    void componentComplete();

    bool running() const
    {
        return m_running;
    }

    bool isNetworkReady() const
    {
        return m_networkReady;
    }

    QServiceDiscoveryFilter *filter() const
    {
        return m_filter;
    }

    bool isLookupReady() const
    {
        return m_lookupReady;
    }

    LookupMode lookupMode() const
    {
        return m_lookupMode;
    }

    int unicastLookupInterval() const
    {
        return m_unicastLookupInterval;
    }

    QQmlListProperty<QServiceList> serviceLists();
    int serviceListCount() const;
    QServiceList *serviceList(int index) const;

    QQmlListProperty<QNameServer> nameServers();
    int nameServerCount() const;
    QNameServer *nameServer(int index) const;

public slots:
    void setRunning(bool arg);
    void setFilter(QServiceDiscoveryFilter *arg);
    void setLookupMode(LookupMode arg);
    void setUnicastLookupInterval(int arg);
    void updateServices();
    void updateFilter();
    void updateNameServers();
    void addNameServer(QNameServer *nameServer);
    void removeNameServer(int index);
    void clearNameServers();

signals:
    void runningChanged(bool arg);
    void networkReadyChanged(bool arg);
    void filterChanged(QServiceDiscoveryFilter *arg);
    void lookupReadyChanged(bool arg);
    void lookupModeChanged(LookupMode arg);
    void unicastLookupIntervalChanged(int arg);
    void nameServersChanged(QQmlListProperty<QNameServer> arg);

private:
    bool m_componentCompleted;
    bool m_running;
    bool m_networkReady;
    bool m_lookupReady;
    LookupMode m_lookupMode;
    int m_unicastLookupInterval;
    QServiceDiscoveryFilter *m_filter;
    QList<QServiceList*> m_serviceLists;
    QList<QNameServer*> m_nameServers;

    QNetworkSession *m_networkSession;
    QNetworkConfigurationManager *m_networkConfigManager;
    QTimer *m_networkConfigTimer; // Timer for refreshing the network status

    QJDns *m_jdns;
    QMap<int, QJDns::Type> m_queryIdTypeMap; // queryId > type
    QMap<int, QServiceDiscoveryItem *> m_queryIdItemMap; // queryId > item
    QMap<int, QString> m_queryIdServiceMap; // queryId > serviceType
    QMap<QString, QList<QServiceDiscoveryItem*> > m_serviceItemsMap; // serviceType > items
    QMap<QString, QJDns::Type> m_serviceTypeMap; // serviceType > queryType

    QTimer *m_unicastLookupTimer;

    void initializeNetworkSession();
    void startQueries();
    void stopQueries();
    void startQuery(QString serviceType);
    void stopQuery(QString serviceType);
    void refreshQuery(QString serviceType);
    void stopItemQueries(QServiceDiscoveryItem *item);
    void addServiceType(QString serviceType, QJDns::Type queryType);
    void removeServiceType(QString serviceType);
    void updateServiceType(QString serviceType);
    void removeAllServiceTypes();
    void updateAllServiceTypes();
    static bool filterServiceDiscoveryItem(QServiceDiscoveryItem *item, QServiceDiscoveryFilter *serviceDiscoveryFilter);
    static QList<QServiceDiscoveryItem *> filterServiceDiscoveryItems(QList<QServiceDiscoveryItem *> serviceDiscoveryItems, QServiceDiscoveryFilter *primaryFilter, QServiceDiscoveryFilter *secondaryFilter);
    QServiceDiscoveryItem *addItem(QString name, QString type);
    QServiceDiscoveryItem *getItem(QString name, QString type);
    void updateItem(QString name, QString type);
    void removeItem(QString name, QString type);
    void clearItems(QString type);
    void purgeItems(QString serviceType);

private slots:
    void resultsReady(int id, const QJDns::Response &results);
    void error(int id, QJDns::Error e);
    void openNetworkSession();
    void updateNetConfig();
    bool initializeMdns();
    void deinitializeMdns();
    void networkSessionOpened();
    void networkSessionClosed();
    void networkSessionError(QNetworkSession::SessionError error);
    void unicastLookup();
};

#endif // QAPPDISCOVERY_H
