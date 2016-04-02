#ifndef INFOTAB_H
#define INFOTAB_H

#include <QWidget>
#include <vector>
#include "SpecificationWindow.h"

// Forward Declarations
class QHBoxLayout;
class QLabel;
class QPushButton;
class QLineEdit;

class InfoTab : public QWidget
{
   // Meta object compiler macro
   Q_OBJECT
      
      public:
   // Default constructor
   InfoTab();
   void updateBudget(double);
   
   // Destructor of class
   ~InfoTab();
   
  signals:
   
   void budgetupdated(double); 
   
   public slots:
   void resizeEvent(QResizeEvent*);
   void budget_submission();
   void text_change(const QString &);
   
   
  private:
   std::vector<QHBoxLayout*> layouts;
   std::vector<QLabel*> information;
   QPushButton* update_budget;
   QLineEdit* budget_in;
   double budget;
   bool parseBudgetAmount(QString);
   
   
   
   
};
#endif
