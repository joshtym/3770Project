#ifndef MOTHERBOARDWINDOW_H
#define MOTHERBOARDWINDOW_H

#include <QWidget>
#include <vector>
#include "SpecificationWindow.h"

// Forward Declarations
class QHBoxLayout;
class QCheckBox;
class QLabel;
class QPushButton;
class QPixMap;

class MotherboardWindow : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
      MotherboardWindow();
      
      // Destructor of class
      ~MotherboardWindow();
   
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
      std::vector<QLabel*> itemPrices;
      std::vector<QLabel*> productImages;
      std::vector<QPixmap> pixMaps;
      std::vector<SpecificationWindow*> specWindows;
};
#endif
