#ifndef PARTPICKERWINDOW_H
#define PARTPICKERWINDOW_H

#include <QMainWindow>
#include "ProcessorWindow.h"

// Forward Declarations
class QTabBar;

class PartPickerWindow : public QMainWindow
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      /// Constructor for the mainWindow
      PartPickerWindow();
   
   private slots:
      void updateWindow(int);
      
   private:
      QTabBar* tabBar;
      ProcessorWindow* cpuWindow;
      int currentTab;
};

#endif
