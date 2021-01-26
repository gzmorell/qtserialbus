/****************************************************************************
**
** Copyright (C) 2021 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtSerialBus module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
****************************************************************************/

#ifndef QMODBUS_SYMBOLS_P_H
#define QMODBUS_SYMBOLS_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

enum Coil {
    On = 0xff00,
    Off = 0x0000
};

namespace Diagnostics {

enum SubFunctionCode {
    ReturnQueryData = 0x0000,
    RestartCommunicationsOption = 0x0001,
    ReturnDiagnosticRegister = 0x0002,
    ChangeAsciiInputDelimiter = 0x0003,
    ForceListenOnlyMode = 0x0004,
    ClearCountersAndDiagnosticRegister = 0x000a,
    ReturnBusMessageCount = 0x000b,
    ReturnBusCommunicationErrorCount = 0x000c,  // CRC error counter
    ReturnBusExceptionErrorCount = 0x000d,
    ReturnServerMessageCount = 0x000e,
    ReturnServerNoResponseCount = 0x000f,
    ReturnServerNAKCount = 0x0010,
    ReturnServerBusyCount = 0x0011,
    ReturnBusCharacterOverrunCount = 0x0012,
    ClearOverrunCounterAndFlag = 0x0014
};

}

namespace EncapsulatedInterfaceTransport {

enum SubFunctionCode {
    CanOpenGeneralReference = 0x0D,
    ReadDeviceIdentification = 0x0E
};

}

#endif // QMODBUS_SYMBOLS_P_H
