﻿//  -----------------------------------------------------------------------------------------
//    QSVEnc by rigaya
//  -----------------------------------------------------------------------------------------
//   ソースコードについて
//   ・無保証です。
//   ・本ソースコードを使用したことによるいかなる損害・トラブルについてrigayaは責任を負いません。
//   以上に了解して頂ける場合、本ソースコードの使用、複製、改変、再頒布を行って頂いて構いません。
//  -----------------------------------------------------------------------------------------

#ifndef __QSV_LOG_H__
#define __QSV_LOG_H__

#include <cstdint>
#include <thread>
#include <mutex>
#include "qsv_tchar.h"
#include "qsv_prm.h"

class CQSVLog {
protected:
    int m_nLogLevel = QSV_LOG_INFO;
    const TCHAR *m_pStrLog = nullptr;
    bool m_bHtml = false;
    std::mutex m_mtx;
    static const char *HTML_FOOTER;
public:
    CQSVLog(const TCHAR *pLogFile, int log_level = QSV_LOG_INFO) {
        init(pLogFile, log_level);
    };
    virtual ~CQSVLog() {
    };
    void init(const TCHAR *pLogFile, int log_level = QSV_LOG_INFO);
    void writeHtmlHeader();
    void writeFileHeader(const TCHAR *pDstFilename);
    void writeFileFooter();
    int getLogLevel() {
        return m_nLogLevel;
    }
    int setLogLevel(int newLogLevel) {
        int prevLogLevel = m_nLogLevel;
        m_nLogLevel = newLogLevel;
        return prevLogLevel;
    }
    bool logFileAvail() {
        return m_pStrLog != nullptr;
    }
    virtual void write_log(int log_level, const TCHAR *buffer, bool file_only = false);
    virtual void write(int log_level, const TCHAR *format, ...);
    virtual void write(int log_level, const WCHAR *format, va_list args);
    virtual void write(int log_level, const char *format, va_list args, uint32_t codepage = CP_THREAD_ACP);
    virtual void write_line(int log_level, const char *format, va_list args, uint32_t codepage = CP_THREAD_ACP);
};


#endif //__QSV_LOG_H__
