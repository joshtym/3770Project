#include <QtGui>
#include "PartPickerWindow.h"

int main(int argc, char* argv[])
{
	// Application initializer
	QApplication app(argc, argv);
	
	// Initialize our window
	PartPickerWindow ppWindow;
	
	// Let's set an appropriate window title
	ppWindow.setWindowTitle("PC Part Picker");
	
	// Now show our window
	ppWindow.show();
	
	return app.exec();
}
