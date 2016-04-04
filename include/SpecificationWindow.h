#ifndef SPECIFICATIONWINDOW_H
#define SPECIFICATIONWINDOW_H

#include <QDialog>

// Forward Declarations
class QVBoxLayout;

class SpecificationWindow : public QDialog
{
   Q_OBJECT
   
   public:
      // Constructor
      SpecificationWindow(QWidget* parent = 0);
      
      // Destructor
      ~SpecificationWindow();
      
      // Public function to add widgets
      void addWidget(QWidget*);
      
   private:
      // Layout for the window
      QVBoxLayout* mainLayout;
};

#endif
