#ifndef PARTPICKERWINDOW_H
#define PARTPICKERWINDOW_H

#include <QMainWindow>
#include <vector>
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
class QString;

class PartPickerWindow : public QMainWindow
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      /// Constructor for the mainWindow
      PartPickerWindow();
   
   private slots:
      void receiveAmountUpdate(double, double, QString);
      
   private:
      bool parseBudgetAmount(QString);
      
      QTabWidget* tabBar;
      ProcessorWindow* cpuWindow;
      MotherboardWindow* mbWindow;
      RamWindow* ramWindow;
      HardDriveWindow* hddWindow;
      InfoTab* infoWindow;
      std::vector<QScrollArea*> tabPages;
      std::vector<QString> productSelectionNames;
      std::vector<double> productSelectionPrices;
      QLabel* currentSpent;
      double budgetAmount;
      double totalAmount;
};

#endif
