#ifndef RAMWINDOW_H
#define RAMWINDOW_H

#include <QWidget>
#include <vector>
#include "SpecificationWindow.h"

// Forward Declarations
class QHBoxLayout;
class QCheckBox;
class QLabel;
class QPushButton;
class QPixMap;

class RamWindow : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
      RamWindow();
      
      // Destructor of class
      ~RamWindow();
   
   signals:
      void sendNewBoxUpdate(double, double);
      
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
      
      std::vector<QHBoxLayout*> layouts;
      std::vector<QCheckBox*> boxOptions;
      std::vector<QPushButton*> expandableButtons;
      std::vector<QLabel*> itemPriceLabels;
      std::vector<double> itemPrices;
      std::vector<QLabel*> productImages;
      std::vector<QPixmap> pixMaps;
      std::vector<SpecificationWindow*> specWindows;
      int currentlyCheckedBox;
};
#endif
