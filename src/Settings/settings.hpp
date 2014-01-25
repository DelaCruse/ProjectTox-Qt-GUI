/*
    Copyright (C) 2013 by Maxim Biro <nurupo.contributions@gmail.com>
    
    This file is part of Tox Qt GUI.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    
    See the COPYING file for more details.
*/

#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QMainWindow>
#include <QHash>

class Settings : public QObject
{
    Q_OBJECT
public:
    static Settings& getInstance();
    ~Settings();

    void executeSettingsDialog(QWidget* parent);

    struct DhtServer
    {
        QString name;
        QString userId;
        QString address;
        int port;
    };

    const QList<DhtServer>& getDhtServerList() const;
    void setDhtServerList(const QList<DhtServer>& newDhtServerList);

    QString getUsername() const;
    void setUsername(const QString& newUsername);

    QString getStatusMessage() const;
    void setStatusMessage(const QString& newMessage);

    bool getEnableLogging() const;
    void setEnableLogging(bool newValue);

    bool getEncryptLogs() const;
    void setEncryptLogs(bool newValue);

    void loadWindow(QMainWindow* window) const;
    // Assumes all windows have unique objectName set
    void saveWindow(const QMainWindow* window);

    bool isAnimationEnabled() const;
    void setAnimationEnabled(bool newValue);

    QByteArray getSmileyPack() const;
    void setSmileyPack(const QByteArray &value);

    bool isCurstomEmojiFont() const;
    void setCurstomEmojiFont(bool value);

    QString getEmojiFontFamily() const;
    void setEmojiFontFamily(const QString &value);

    int getEmojiFontPointSize() const;
    void setEmojiFontPointSize(int value);

    // ChatView
    int getFirstColumnHandlePos() const;
    void setFirstColumnHandlePos(const int pos);

    int getSecondColumnHandlePos() const;
    void setSecondColumnHandlePos(const int pos);

private:
    Settings();
    Settings(Settings &settings) = delete;
    Settings& operator=(const Settings&) = delete;

    void save();
    void load();

    static const QString FILENAME;

    bool loaded;

    QList<DhtServer> dhtServerList;
    int dhtServerId;
    bool dontShowDhtDialog;

    QString username;
    QString statusMessage;

    bool enableLogging;
    bool encryptLogs;

    struct WindowSettings
    {
        QByteArray geometry;
        QByteArray state;
    };

    QHash<QString, WindowSettings> windowSettings;

    // GUI
    bool enableSmoothAnimation;
    QByteArray smileyPack;
    bool customEmojiFont;
    QString emojiFontFamily;
    int     emojiFontPointSize;

    // ChatView
    int firstColumnHandlePos;
    int secondColumnHandlePos;

signals:
    //void dataChanged();
    void dhtServerListChanged();
    void logStorageOptsChanged();
    void smileyPackChanged();
    void emojiFontChanged();
};

#endif // SETTINGS_HPP
