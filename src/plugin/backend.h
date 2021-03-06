/*
 *
 * Copyright 2020 Gustavo Castro <gustawho@gmail.com>
 *
 * This file is part of Plastweet.
 *
 * Plastweet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Plastweet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Plastweet.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef BACKEND_H
#define BACKEND_H

#include <string>

#include <QObject>

#include <KNotification>
#include <KLocalizedString>

#include "./twitcurl/twitcurl.h"

class BackEnd : public QObject {
	Q_OBJECT
public:
	explicit BackEnd(QObject *parent = 0);
	~BackEnd();
	
	Q_INVOKABLE void send_tweet(
		const QString &message,
		const QString &image,
		const QString &consumer_key,
		const QString &consumer_secret,
		const QString &user_token,
		const QString &token_secret
	);
	bool execMain(
		std::string message,
		std::string image,
		std::string consumer_key,
		std::string consumer_secret,
		std::string user_token,
		std::string token_secret
	);
	Q_SCRIPTABLE void sendNotification(
		const QString &eventId,
		const QString &iconName,
		const QString &title,
		const QString &text
	) {
		KNotification* notification = new KNotification(eventId);
		notification->setIconName(iconName);
		notification->setComponentName(QStringLiteral("plastweet"));
		notification->setTitle(title);
		notification->setText(text);
		notification->sendEvent();
	}
signals:
	
private:
	twitCurl twitter;
	std::string api_response;
};

#endif
