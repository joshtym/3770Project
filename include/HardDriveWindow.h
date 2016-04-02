#ifndef HARDDRIVEWINDOW_H
#define HARDDRIVEWINDOW_H

#include <QWidget>
#include <vector>
#include "SpecificationWindow.h"

// Forward Declarations
class QHBoxLayout;
class QCheckBox;
class QLabel;
class QPushButton;
class QPixMap;
class QString;
class QScrollArea;
class QVBoxLayout;

class HardDriveWindow : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
      HardDriveWindow();
      
      // Destructor of class
      ~HardDriveWindow();
      
      void updateCurrentAmount(double);
      void updateBudgetAmount(double);
   
   signals:
      void sendNewBoxUpdate(double, double, QString);
      
   private slots:
      void updateBoxOne(int);
      void updateBoxTwo(int);
      void updateBoxThree(int);
      void updateBoxFour(int);
      void updateBoxFive(int);
      void updateBoxSix(int);
      void openWindowOne();
      void openWindowTwo();
      void openWindowThree();
      void openWindowFour();
      void openWindowFive();
      void openWindowSix();
   
   public slots:
      void resizeEvent(QResizeEvent*);
   
   private:
      void loadAssets();
      void loadSpecs();
      
      std::vector<QHBoxLayout*> layouts;
      std::vector<QCheckBox*> boxOptions;
      std::vector<QPushButton*> expandableButtons;
      std::vector<QLabel*> itemPriceLabels;
      std::vector<double> itemPrices;
      std::vector<QLabel*> productImages;
      std::vector<QPixmap> pixMaps;
      std::vector<SpecificationWindow*> specWindows;
      std::vector<QScrollArea*> specScrollAreas;
      std::vector<QWidget*> specCentralWidgets;
      std::vector<QVBoxLayout*> specLayouts;
      int currentlyCheckedBox;
      double currentAmount;
      double budgetAmount;
};
#endif
