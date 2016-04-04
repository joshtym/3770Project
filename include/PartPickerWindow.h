#ifndef PARTPICKERWINDOW_H
#define PARTPICKERWINDOW_H

#include <QMainWindow>
#include <vector>
#include "InfoWindow.h"
#include "ConfirmationWindow.h"
#include "PartPageInterface.h"

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
      // Constructor for the mainWindow
      PartPickerWindow();
      
   private slots:
      // Private slot to update current costs
      void receiveAmountUpdate(double, double, QString);
      
      // Private slot to update the budget
      void budgetUpdated(double);
      
      // Private slot to reset the entire board
      void resetSelection();
      
   private:
      // Private helper function to parse the QString from initial input
      bool parseBudgetAmount(QString);
      
      // Private helper function to adjust available options for MOBO and CPU
      void adjustAvailableOptions(QString, bool);
      
      // Private Variables
      QTabWidget* tabBar;
      PartPageInterface* cpuWindow;
      PartPageInterface* mbWindow;
      PartPageInterface* ramWindow;
      PartPageInterface* hddWindow;
      InfoWindow* infoWindow;
      ConfirmationWindow* confWindow;
      std::vector<QScrollArea*> tabPages;
      QLabel* currentSpent;
      QLabel* budget;
      QString budgetAmountString;
      double budgetAmount;
      double totalAmount;
};

#endif
