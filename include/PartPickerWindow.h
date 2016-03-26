#ifndef PARTPICKERWINDOW_H
#define PARTPICKERWINDOW_H

#include <QMainWindow>
#include "ProcessorWindow.h"
#include "MotherboardWindow.h"

// Forward Declarations
class QTabWidget;
class QScrollArea;

class PartPickerWindow : public QMainWindow
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      /// Constructor for the mainWindow
      PartPickerWindow();
      
   private:
      QTabWidget* tabBar;
      ProcessorWindow* cpuWindow;
      MotherboardWindow* mbWindow;
      std::vector<QScrollArea*> tabPages;
};

#endif
