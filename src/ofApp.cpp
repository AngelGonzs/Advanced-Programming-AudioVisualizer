#include "ofApp.h"
#include <string>
float R = ofRandom(255);
float G = ofRandom(255);
float B = ofRandom(200);
//--------------------------------------------------------------
void ofApp::setup(){
    sound.loadSound("beat.wav"); //Loads a sound file (in bin/data/)
    sound.setLoop(true); // Makes the song loop indefinitely
    sound.setVolume(vol); // Sets the song volume
    ofSetBackgroundColor(200, 50,10); // Sets the Background Color
}

//--------------------------------------------------------------
void ofApp::update(){
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSoundUpdate(); // Updates all sound players
    if (drawing){// Updates Amplitudes for visualizer
        visualizer.updateAmplitudes();
        } 
}

//--------------------------------------------------------------
void ofApp::draw(){
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    if(!playing){
        ofSetColor(256); //so that the text can be white
        ofDrawBitmapString("Press 'p' to play some music!", ofGetWidth()/2 - 50, ofGetHeight()/2);
    }
    vector<float> amplitudes = visualizer.getAmplitudes();
    if(mode == '1'){
        drawMode1(amplitudes);
    }else if(mode == '2'){
        drawMode2(amplitudes);
    }else if(mode == '3'){
        drawMode3(amplitudes);
    }else if(mode == '4'){
        drawMode4(amplitudes);
    }
}
void ofApp::drawMode1(vector<float> amplitudes){
        ofFill(); // Drawn Shapes will be filled in with color
        ofSetColor(256); // This resets the color of the "brush" to white
        ofDrawBitmapString("Rectangle Height Visualizer", 0, 15);
        // ofDrawBitmapString(amplitudes[0], 10, 30);



        ofSetColor(R, G, B); //Changed color so that the rectangles can look different
        int total = 0;
        int bands = amplitudes.size();
        for(int i=0; i<bands;i++){
            ofDrawRectangle(total, ofGetHeight() - 100, 50,  amplitudes[i]*2);
            total += (ofGetWidth()/64); //1024 divided between 64 = 16 :)
        }

}
void ofApp::drawMode2(vector<float> amplitudes){
        ofSetLineWidth(5); // Sets the line width
        ofNoFill(); // Only the outline of shapes will be drawn
        ofSetColor(256); // This resets the color of the "brush" to white


        ofDrawBitmapString("Circle Radius Visualizer", 0, 15);
        int bands = amplitudes.size();
        for(int i=0; i< bands; i++){
            ofSetColor((bands - i)*32 %256,18,144); // Color varies between frequencies
            ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, amplitudes[0]/(i +1));
        }
}

void ofApp::drawMode3(vector<float> amplitudes){
    ofFill();
    ofSetColor(256); // This resets the color of the "brush" to white
    ofDrawBitmapString("Rectangle Width Visualizer", 0, 15);
    ofSetColor(B,G,R);


    int total = 0;
    int bands = amplitudes.size();
    for(int i=0; i<bands;i++){
        ofDrawRectangle( ofGetWidth(), total, amplitudes[i]*2,50  );
        total += (ofGetHeight()/64);} 

    //done with this method
    /*ofDrawRectangle uses cordinates (x,y) so I inverted the values 
    so that they could be focused on the y axis instead of the x axis
    as it was in the first rectangle method */
    
}
void ofApp::drawMode4(vector<float> amplitudes){
    ofSetColor(256); // This resets the color of the "brush" to white
    ofDrawBitmapString("Custom Visualizer", 0, 15);

    ofFill();
    ofSetColor(0,0,0); //Sets color to black

    int counter = 0;
    int counter2 = 16; //two counters to alter the X variable in ofDrawLine() method 
    int half = ofGetHeight()/2; //Locates lines at half of screen :) in the y axis
    int bands = amplitudes.size();
    int adder = ofGetWidth()/amplitudes.size();


    //ofDrawLine uses (x1,y1) and (x2,y2) to draw lines between those 2 points

    /*for loop creates 64 lines, each with a different amplitude thanks to 
    amplitudes[] being a vector which is formed by many different amplitudes
    that are here being accessed with [i] and [i+1]*/

    for(int i =0; i<bands ;i++){
        ofDrawLine(counter, half+ amplitudes[i], counter2,half + amplitudes[i+1]);
        counter += adder;
        counter2 += adder;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // This method is called automatically when any key is pressed
    switch(key){
        case 'p':
            if(playing){
                sound.stop();
            }else{
                sound.play();
            }
            playing = !playing;
            break;
        case '1':
            mode = '1';
            break;
        case '2':
            mode = '2';
            break;
        case '3':
            mode = '3';
            break;
        case '4':
            mode = '4';
            break;


        case 'a': 
            if(drawing){
                drawing = false;
                
            }else{
                drawing = true;
            }
            break;


        case '7':
            sound.loadSound("beat.wav");
            sound.play();
            break;
        case '8':
            sound.loadSound("geesebeat.wav");
            sound.play();
            break;
        case '9':
            sound.loadSound("Play-em-like-atari.wav");
            sound.play();
            break;
        case '0':
            sound.loadSound("rock-song.wav");
            sound.play();
            break;


        case '=':
            if(vol<1){
            vol += 0.1;
            sound.setVolume(vol);
            break;
            }
            break;

        case '-':
            if(vol>0){
            vol -= 0.1;
            sound.setVolume(vol);
            break;
            }
            break;


    }
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}