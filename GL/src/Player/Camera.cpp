//
//  Camera.cpp
//  learn
//
//  Created by Chen.Zr on 2019/10/11.
//  Copyright © 2019 Chen.Zr. All rights reserved.
//
#include <iostream>

#include "Camera.hpp"

Camera::Camera(glm::vec3 cameraPosition, glm::vec3 worldUp, glm::vec3 front,
               GLfloat yaw, GLfloat pitch, GameSetting *setting){
    setCamera(cameraPosition, worldUp, front,
              yaw, pitch, setting -> speed, setting -> sensitivity, setting -> fov);
    this -> setting = setting;
}

Camera::Camera(glm::vec3 cameraPosition, GameSetting *setting){
    setCamera(cameraPosition,
              glm::vec3(0.0,1.0,0.0),
              glm::vec3(0.0,0.0,-1.0),
              -90.0f, 0.0f,
              setting -> speed,
              setting -> sensitivity,
              setting -> fov);
    
    this -> setting = setting;
}

void Camera::setCamera(glm::vec3 cameraPosition, glm::vec3 worldUp, glm::vec3 front,
                       GLfloat yaw, GLfloat pitch, GLfloat speed, GLfloat sensitivity, GLfloat fov) {
    this -> position = cameraPosition;
    this -> WorldUp = worldUp;
    
    this->Yaw = yaw;
    this->Pitch = pitch;
    this->MovementSpeed = speed;
    this->Sensitivity = sensitivity;
    this->fov = fov;
    
    this->updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() const{ 
    return glm::lookAt(this->position, this->position + this->Front, this->WorldUp);
}

void Camera::ProcessMovement(Camera_Movement direction, GLfloat deltaTime) {
    GLfloat y = position.y;
    GLfloat velocity = this->MovementSpeed * deltaTime;
    if (direction == FORWARD) {
        this->position += this->Front * velocity;
    }
    if (direction == BACKWARD) {
        this->position -= this->Front * velocity;
    }
    if (direction == RIGHT) {
        this->position -= this->Right * velocity;
    }
    if (direction == LEFT) {
        this->position += this->Right * velocity;
    }
    position.y = y;
}

void Camera::ProcessMouseMovement(GLfloat offsetX, GLfloat offsetY) {
    offsetX *= this->Sensitivity;
    offsetY *= this->Sensitivity;
    Yaw -= offsetX;
    Pitch -= offsetY;
    if (this->Pitch > 89.0) {
        this->Pitch = 89.0;
    }
    if (this->Pitch < -89.0){
        this->Pitch = -89.0;
    }
    this->updateCameraVectors();
}

//void Camera::ProcessMouseScroll(GLfloat offsetY) { 
//    if(this->fov >= 1.0 && this->fov <= 45.0){
//        this->fov -= offsetY * 0.1;
//    }else if (this->fov <= 1.0){
//        this->fov = 1.0;
//    }else if (this->fov >= 45.0){
//        this->fov = 45.0;
//    }
//}

void Camera::updateCameraVectors() {
    glm::vec3 front(0.0,0.0,-1.0);
    front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    front.y = sin(glm::radians(this->Pitch));
    front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    this->Front = glm::normalize(front);
    this->Right = glm::normalize(glm::cross(this->Front,this->WorldUp));
    this->Up = glm::normalize(glm::cross(this->Right, this->Front));
}

glm::mat4 Camera::getPerspectiveMatrix() const {
    return glm::perspective(setting->fov, (float)setting->width/setting->height, 0.01f, 1000.0f);
}

void Camera::ProcessVerticality(Camera_Movement direction, GLfloat deltaTime) { 
    GLfloat velocity = this->MovementSpeed * deltaTime;
    if (direction == ABOVE) {
        this->position -= this->WorldUp * velocity;
    }
    if (direction == BOTTOM) {
        this->position += this->WorldUp * velocity;
    }
}





