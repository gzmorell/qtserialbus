/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtSerialBus module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef DUMMYBACKEND_H
#define DUMMYBACKEND_H

#include <QtSerialBus/qcanbusdevice.h>

#include <QtCore/qbytearray.h>
#include <QtCore/qpointer.h>

QT_BEGIN_NAMESPACE

class QTimer;

class DummyBackend : public QCanBusDevice
{
    Q_OBJECT
public:
    explicit DummyBackend();

    bool open() Q_DECL_OVERRIDE;
    void close() Q_DECL_OVERRIDE;

    void setConfigurationParameter(const QString &key, const QVariant &value) Q_DECL_OVERRIDE;
    QVariant configurationParameter(const QString &key) const Q_DECL_OVERRIDE;
    QVector<QString> configurationKeys() const Q_DECL_OVERRIDE;

    qint64 availableFrames() const Q_DECL_OVERRIDE;
    QCanFrame readFrame() Q_DECL_OVERRIDE;
    bool writeFrame(const QCanFrame &data) Q_DECL_OVERRIDE;

public Q_SLOTS:
    void sendMessage();

private:
    QPointer<QTimer> sendTimer;
    QByteArray byteArray;
};

QT_END_NAMESPACE

#endif // DUMMYBACKEND_H
