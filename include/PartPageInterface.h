#ifndef PARTPAGEINTERFACE_H
#define PARTPAGEINTERFACE_H

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

class PartPageInterface : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Constructor for the Interface
      PartPageInterface();
      
      // Destructor for the interface
      ~PartPageInterface();
      
      // Function to init all our values
      void initValues();
      
      // Function to update the current cost
      void updateCurrentAmount(double);
      
      // Function to update the budget
      void updateBudgetAmount(double);
      
      // Function to reset our selection
      void resetSelection();
      
      // Function to update all of our available options
      void updateAvailableOptions(QString, bool);
      
   public slots:
      // Slot to handle resizes
      void resizeEvent(QResizeEvent*);
      
   signals:
      // Signals sent by this interface
      void sendNewBoxUpdate(double, double, QString);
      
   protected:
      // Pure virtual function to load the specs
      virtual void loadSpecs() = 0;
      
      // Pure virtual function to load our assets
      virtual void loadAssets() = 0;
      
      // Pure virtual function to init our vector values
      virtual void initVectorValues() = 0;
      
      // Protected variables for the interface
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
      std::vector<QLabel*> stringRecognizers;
      QVBoxLayout* mainLayout;
      int currentlyCheckedBox;
   
   protected slots:
      // Slot called when check box one is changed
      void updateBoxOne(int);
      
      // Slot called when check box two is changed
      void updateBoxTwo(int);
      
      // Slot called when check box three is changed
      void updateBoxThree(int);
      
      // Slot called when check box four is changed
      void updateBoxFour(int);
      
      // Slot called when check box five is changed
      void updateBoxFive(int);
      
      // Slot called when check box six is changed
      void updateBoxSix(int);
      
      // Slot called when the button is clicked for window one
      void openWindowOne();
      
      // Slot called when the button is clicked for window two
      void openWindowTwo();
      
      // Slot called when the button is clicked for window three
      void openWindowThree();
      
      // Slot called when the button is clicked for window four
      void openWindowFour();
      
      // Slot called when the button is clicked for window five
      void openWindowFive();
      
      // Slot called when the button is clicked for window six
      void openWindowSix();
      
   private:
      // Private variables for the interface
      double currentAmount;
      double budgetAmount;
};
#endif
