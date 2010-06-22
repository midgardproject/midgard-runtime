#include "phpprocess.h"
#include <QDebug>
#include <pwd.h>

PhpProcess::PhpProcess(QDir baseDir, QObject *parent) : RuntimeProcess(baseDir, parent)
{
}

void PhpProcess::start()
{
    QStringList arguments;
    QStringList env;

    arguments << "-c";
    arguments << "php.ini";
    arguments << "midgardmvc_core/httpd/midcom-root-mjolnir-appserv.php";
    
    // Standard env
    env << ("MIDGARD_ENV_GLOBAL_CACHEDIR=" + baseDir.absoluteFilePath("cache"));
    env << ("MIDGARD_ENV_GLOBAL_SHAREDIR=" + baseDir.absoluteFilePath("share"));

    // Get the user name and the real name
    struct passwd *userinfo = getpwuid(getuid());
    QString username = QString();
    QString realname = QString();

    if (userinfo->pw_name != NULL)
        username = QString(userinfo->pw_name);

    if (userinfo->pw_gecos != NULL && QString(userinfo->pw_gecos).split(',').size() > 0)
        realname = QString(userinfo->pw_gecos).split(',').at(0);

    env << ("MIDGARD_ENV_USER_NAME=" + username);
    env << ("MIDGARD_ENV_REAL_NAME=" + realname);

    setEnvironment(env);
    QProcess::start("php5", arguments);
    sleep(1); // FIXME A bit ugly but for now...
}
