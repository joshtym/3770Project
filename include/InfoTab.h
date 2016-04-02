#ifndef INFOTAB_H
#define INFOTAB_H

#include <QWidget>
#include <vector>
#include "SpecificationWindow.h"

// Forward Declarations
class QHBoxLayout;
class QLabel;
class QPushButton;
class QPixMap;

class InfoTab : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
   
   public:
      // Default constructor
   InfoTab();
   
   // Destructor of class
   ~InfoTab();
   
   void budgetupdated(double); 

   public slots:
      void resizeEvent(QResizeEvent*);
   
   private:
      std::vector<QHBoxLayout*> layouts;
      std::vector<QLabel*> information;
};
#endif
