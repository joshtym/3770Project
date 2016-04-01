#ifndef SPECIFICATIONWINDOW_H
#define SPECIFICATIONWINDOW_H

#include <QWidget>

// Forward Declarations
class QVBoxLayout;

class SpecificationWindow : public QWidget
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
