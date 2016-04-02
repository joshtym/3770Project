#ifndef PARTPICKERWINDOW_H
#define PARTPICKERWINDOW_H

#include <QMainWindow>
#include "ProcessorWindow.h"
#include "MotherboardWindow.h"
#include "RamWindow.h"
#include "HardDriveWindow.h"
#include "InfoTab.h"

// Forward Declarations
class QTabWidget;
class QScrollArea;
class QString;
class QLabel;

class PartPickerWindow : public QMainWindow
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      /// Constructor for the mainWindow
      PartPickerWindow();
   
   private slots:
      void receiveAmountUpdate(double, double);
      
   private:
      bool parseBudgetAmount(QString);
      
      QTabWidget* tabBar;
      ProcessorWindow* cpuWindow;
      MotherboardWindow* mbWindow;
      RamWindow* ramWindow;
      HardDriveWindow* hddWindow;
      InfoTab* infoWindow;
      std::vector<QScrollArea*> tabPages;
      QLabel* currentSpent;
      double budgetAmount;
      double totalAmount;
};

#endif
