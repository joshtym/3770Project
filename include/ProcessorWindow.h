#ifndef PROCESSORWINDOW_H
#define PROCESSORWINDOW_H

#include <QWidget>
#include <vector>

// Forward Declarations
class QCheckBox;
class QLabel;

class ProcessorWindow : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
      ProcessorWindow();
      
      // Destructor of class
      ~ProcessorWindow();
   
   private:
      std::vector<QCheckBox*> boxOptions;
      std::vector<QLabel*> boxNames;
};
#endif
