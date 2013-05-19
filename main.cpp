#include "hoggui.h"
#include <QtGui/QApplication>
#include "feature2person.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HogGui w;
	w.show();
	return a.exec();
	//posittest();
}
