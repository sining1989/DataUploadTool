#ifndef DATA_UPLOAD_FFMPEGCMD_H
#define DATA_UPLOAD_FFMPEGCMD_H

#include <QThread>
#include <QProcess>
#include <QApplication>
#include <QFileInfo>
#include <QMap>

class FfmpegCmd : public QThread
{
    Q_OBJECT

    public:
        void videoToBitmap(QString path) {
            m_path = path;
            m_args.clear();
            m_args.append("-i");
            m_args.append(path);
            m_args.append("-y");
            m_args.append("-f");
            m_args.append("image2");
			m_args.append("-t");
			m_args.append("0.001");
			m_args.append("-s");
			m_args.append("320*240");
			QString strPath = path.replace(".mp4", ".jpg");
            m_args.append(strPath);
            start();
        }

        void run(){
            QProcess p(0);
            p.setWorkingDirectory(QApplication::applicationDirPath());
            QString cmd = "ffmpeg/ffmpeg.exe";
            p.execute(cmd, m_args);
            p.waitForFinished();
			m_videoStatueMap.insert(m_args[9], true);
        }
		


    public:
        QStringList m_args;
        QString m_path;
		QMap<QString, bool> m_videoStatueMap;
};

#endif // DATA_UPLOAD_FFMPEGCMD_H
