#ifndef RAMWINDOW_H
#define RAMWINDOW_H

#include "PartPageInterface.h"

class RamWindow : public PartPageInterface
{
   public:
      // Constructor
      RamWindow();
      
      // Destructor
      ~RamWindow();
   
   protected:
      // Instantiated virtual function to initialize our vector values
      virtual void initVectorValues();
      
      // Instantiated virtual function to update info for spec windows
      virtual void loadSpecs();
      
      // Instantiated virtual function to load our iamges
      virtual void loadAssets();
};
#endif
