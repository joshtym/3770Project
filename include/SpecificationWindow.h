#ifndef SPECIFICATIONWINDOW_H
#define SPECIFICATIONWINDOW_H

#include <QDialog>

// Forward Declarations
class QVBoxLayout;

class SpecificationWindow : public QDialog
{
   Q_OBJECT
   
   public:
      SpecificationWindow();
      ~SpecificationWindow();
      void addWidget(QWidget*);
      
   private:
      QVBoxLayout* mainLayout;
};

#endif
