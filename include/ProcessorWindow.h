#ifndef PROCESSORWINDOW_H
#define PROCESSORWINDOW_H

#include <QWidget>
#include <vector>

// Forward Declarations
class QHBoxLayout;
class QCheckBox;
class QLabel;
class QPushButton;
class QPixMap;

class ProcessorWindow : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
      ProcessorWindow();
      
      // Destructor of class
      ~ProcessorWindow();
   
   private slots:
      void updateBoxOne(int);
      void updateBoxTwo(int);
      void updateBoxThree(int);
      void updateBoxFour(int);
      void updateBoxFive(int);
      void updateBoxSix(int);
   
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
};
#endif
