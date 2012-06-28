/****************************************************************************
**
** VKit - vk.com API Qt bindings
**
** Copyright © 2012 Aleksey Sidorov <gorthauer87@ya.ru>
**
*****************************************************************************
**
** $VKIT_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $VKIT_END_LICENSE$
**
****************************************************************************/
#ifndef LONGPOLL_P_H
#define LONGPOLL_P_H

#include "longpoll.h"
#include "client.h"
#include "reply.h"

#include <QVariant>
#include <QTimer>
#include <QUrl>
#include <QNetworkReply>

#include <QDebug>

namespace vk {

class LongPoll;
class LongPollPrivate
{
    Q_DECLARE_PUBLIC(LongPoll)
public:
    LongPollPrivate(LongPoll *q) : q_ptr(q), client(0),
		mode(LongPoll::RecieveAttachments), pollInterval(1500), waitInterval(25), isRunning(false) {}
    LongPoll *q_ptr;
    Client *client;

    LongPoll::Mode mode;
    int pollInterval;
    int waitInterval;
    QUrl dataUrl;
	bool isRunning;

	void _q_request_server_finished(const QVariant &response);
	void _q_on_data_recieved(const QVariant &response);
};


} //namespace vk

#endif // LONGPOLL_P_H

