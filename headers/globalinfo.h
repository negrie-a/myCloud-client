#ifndef GLOBALINFO_H
#define GLOBALINFO_H

#include <QString>

namespace Color {
    class GlobalInfo
    {
    public:
        GlobalInfo();
        static QString grey;
        static QString greySolid;
        static QString lightBlue;
        static QString greyLight;
        static QString white;
        static QString greyBorder;
        static QByteArray sid;
    };
}

namespace Server {
    class GlobalInfo
    {
    public:
        GlobalInfo();
        static QByteArray sid;
    };
}

namespace Font {
    class GlobalInfo
    {
    public:
        GlobalInfo();
        static QString name;
    };
}

#endif // GLOBALINFO_H