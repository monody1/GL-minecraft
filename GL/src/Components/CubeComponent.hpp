//
//  CubeComponent.hpp
//  LearnOpenGL
//
//  Created by Chen.Zr on 2020/1/19.
//  Copyright © 2020 Chen.Zr. All rights reserved.
//

#ifndef CubeComponent_hpp
#define CubeComponent_hpp

#include "BaseComponent.hpp"


class CubeComponent{
    
public:
    std::string name = "cube";
    std::vector<GLfloat> vertextPosition{
        //F
        +1.0, +1.0, +1.0, -1.0, +1.0, +1.0, +1.0, -1.0, +1.0,
        -1.0, -1.0, +1.0, +1.0, -1.0, +1.0, -1.0, +1.0, +1.0,
        //B
        -1.0, +1.0, -1.0, +1.0, +1.0, -1.0, -1.0, -1.0, -1.0,
        +1.0, -1.0, -1.0, -1.0, -1.0, -1.0, +1.0, +1.0, -1.0,
        //L
        -1.0, +1.0, +1.0, -1.0, +1.0, -1.0, -1.0, -1.0, +1.0,
        -1.0, -1.0, -1.0, -1.0, -1.0, +1.0, -1.0, +1.0, -1.0,
        //R
        +1.0, +1.0, -1.0, +1.0, +1.0, +1.0, +1.0, -1.0, -1.0,
        +1.0, -1.0, +1.0, +1.0, -1.0, -1.0, +1.0, +1.0, +1.0,
        //U
        +1.0, +1.0, -1.0, -1.0, +1.0, -1.0, +1.0, +1.0, +1.0,
        -1.0, +1.0, +1.0, +1.0, +1.0, +1.0, -1.0, +1.0, -1.0,
        //D
        +1.0, -1.0, +1.0, -1.0, -1.0, +1.0, +1.0, -1.0, -1.0,
        -1.0, -1.0, -1.0, +1.0, -1.0, -1.0, -1.0, -1.0, +1.0
    };
    std::vector<GLfloat> textureCroods{
        //F
        1.0, 0.0, 0.0, 0.0, 1.0, 1.0,
        0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
        //B
        1.0, 0.0, 0.0, 0.0, 1.0, 1.0,
        0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
        //L
        1.0, 0.0, 0.0, 0.0, 1.0, 1.0,
        0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
        //R
        1.0, 0.0, 0.0, 0.0, 1.0, 1.0,
        0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
        //U
        1.0, 0.0, 0.0, 0.0, 1.0, 1.0,
        0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
        //D
        1.0, 0.0, 0.0, 0.0, 1.0, 1.0,
        0.0, 1.0, 1.0, 1.0, 0.0, 0.0,
    };
    
    Model *model = nullptr;
    
    CubeComponent(){
        model = new Model(vertextPosition, textureCroods);
    };
    
    Model *getComponentModel()
    {
        return model;
    };
    
    ~CubeComponent(){
        delete model;
    };
};



#endif /* CubeComponent_hpp */
