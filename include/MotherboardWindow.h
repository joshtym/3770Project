#ifndef MOTHERBOARDWINDOW_H
#define MOTHERBOARDWINDOW_H

#include <QWidget>
#include <vector>

// Forward Declarations
class QCheckBox;
class QLabel;

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
   
   private:
      std::vector<QCheckBox*> boxOptions;
      std::vector<QLabel*> boxNames;
      std::vector<QLabel*> itemPrices;
};
#endif
