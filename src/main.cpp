#include "MainWindow.h"

#include <QApplication>

#ifdef QT_INCLUDE_PLUGIN
# include <QtPlugin>
#endif

#ifdef QT_INCLUDE_XCB_INTEGRATION_PLUGIN
Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)
#endif

#ifdef QT_INCLUDE_WINDOWS_INTEGRATION_PLUGIN
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)
#endif

#ifdef QT_INCLUDE_COCOA_INTEGRATION_PLUGIN
Q_IMPORT_PLUGIN(QCocoaIntegrationPlugin)
#endif

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow mw;
	mw.show();

	return app.exec();
}
