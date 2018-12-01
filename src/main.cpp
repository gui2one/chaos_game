#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <string>

#include <FreeImagePlus.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


#define PI 3.1415926535
using namespace std;



typedef struct {
	double x, y;
}Point;

bool isFirstFrame = true;
vector<Point> points;


int nPoints = 8;
double amount = 0.55;
float radius = 1.0;
int ignoreN = 0;
float alpha = 0.005;
string outputPath = "zzz.bmp";



int curIter = 0;
int maxIter = 1000000;

bool exitEarly = false;
double lerp(double a, double b, double amount){
	return (b-a) * amount + a ;
}



/*
 * 
 * superb example at http://zarb.org/~gc/html/libpng.html
 * using libpng ( actual code deleted)
 * 
 */

void displayHelp(){
	string str = "usage chaos_game -param value > ouputfile\n";
	str += "-npt : number of starting points\n";
	str += "-r -radius : radius\n";
	str += "-am -amount : amount\n";	
	str += "-ig -ignore : how many last indices to ignore (avoid) 0,1 or 2\n";
	str += "-a -alpha : opacity level of each point\n";
	str += "-max -maxiterations : how many iterations to run begore saving the file to disk\n";
	str += "-o -output : output file\n";
	
	printf("%s", str.c_str());
}

void parseArguments(int argc, char* argv[]){
	
	
	if(argc > 1){
		//~ cout << "there are arguments ...." << argv[1] << "----" << (argv[1] == "-npt" ? "true" : "false")<< "--" << endl;
		int argn = 1;
		while (argn < argc){
			//~ cout << "Looop --> " << argv[argn] << endl;
			string str = argv[argn];
			if(str == "-npt"){
				nPoints = atoi(argv[argn+1]);
				//~ cout << "nPoints --> "<<nPoints << endl;
				argn += 2;
				
			}else if(str == "-r" || str == "-radius"){
				radius = atof(argv[argn+1]);
				//~ cout << "radius --> "<<radius << endl;
				argn += 2;
			}else if(str == "-am" || str == "-amount"){
				amount = atof(argv[argn+1]);
				//~ cout << "amount --> "<<amount << endl;
				argn += 2;
			}else if(str == "-ig" || str == "-ignore"){
				ignoreN = atoi(argv[argn+1]);
				//~ cout << "ignoreN --> "<<ignoreN << endl;
				argn += 2;
			}else if(str == "-a" || str == "-alpha"){
				alpha = atof(argv[argn+1]);
				//~ cout << "alpha --> "<<alpha << endl;
				argn += 2;
			}else if(str == "-max" || str == "-maxiterations"){
				maxIter = atoi(argv[argn+1]);
				//~ cout << "maxIter --> "<<maxIter << endl;
				argn += 2;
			}else if(str == "-o" || str == "-output"){
				outputPath = argv[argn+1];
				cout << "outputPath --> "<<outputPath << endl;
				argn += 2;
			}else if(str == "-h" || str == "-help"){
				displayHelp();
				exitEarly = true;
				break;				
			}else{
				argn++;			
			}
		}
	}
}

int main(int argc, char** argv ){
	

	parseArguments(argc, argv);
	
	if(exitEarly)
		return 0;
	//~ std::cout << "Chaos Game Project" << std::endl;
	
	if(!glfwInit()){
		cout << "problem with GLFW" << endl;
		return 1;
	}else{
		cout << "Starting GLFW" << endl;
		
		GLFWwindow * window = glfwCreateWindow(600,300,"Chaos Game v0.01", NULL, NULL);
		
		if(!window){
			cout << "problem with GLFW window" << endl;
		}else{
			//~ cout << "Creating GLFW Window" << endl;
			glfwMakeContextCurrent(window);
			glfwSwapInterval(1);
			glewInit();
			
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glEnable( GL_BLEND );			
			
			
			
			for (int i = 0; i < nPoints; i++)
			{
				double r = radius;
				Point p;
				p.x = sin((PI*2/(double)nPoints) * i) * r ; //-(0.5 * r);
				p.y = cos((PI*2/(double)nPoints) * i) * r;
				points.push_back(p);
			}
			
			fipImage img;
			//~ img.load("foobar.png");
			
			while(!glfwWindowShouldClose(window)){
				

				
				int width , height;
				glfwGetFramebufferSize(window, &width, &height);
				glViewport(0,0, width, height);
				double ratio = (double)width / height;

				glLoadIdentity();
				glOrtho(-ratio, ratio, -1, 1, -1, 1);

				//~ glClear(GL_COLOR_BUFFER_BIT);
				//~ glClearColor(0.0,0.5,0.2,1.0);

				if(isFirstFrame){
					
					isFirstFrame = false;
					
					glPointSize(5);
					glColor4f(1.0,1.0,0.0,1.0);
					for (int i = 0; i < points.size(); i++)
					{
						
						glBegin(GL_POINTS);
						
						glVertex2f(points[i].x,points[i].y);
						glEnd();					
					}
					
				
					
				}				
				
				
				Point p;
				
				int old_choice = -1;
				int old_old_choice = -1;
				
				p.x = lerp(points[0].x, points[1].x, 0.22);
				p.y = lerp(points[0].y, points[1].y,0.22);
				for (int i = 0; i < 100000; i++)
				{
					int choice = rand() % points.size();
				
					if(ignoreN == 1){
						if( choice == old_choice ){//|| choice == old_old_choice){
							continue;
						}	
					}else if(ignoreN == 2){
						if( choice == old_choice || choice == old_old_choice){
							continue;
						}						
					}
					
					double x = lerp(p.x,points[choice].x, amount);
					double y = lerp(p.y,points[choice].y, amount);
					glPointSize(1);
					glBegin(GL_POINTS);
						glColor4f(1.0,1.0,0.0,alpha);
						glVertex2f(x,y);
					glEnd();
					
					p.x = x;
					p.y = y;
					
					if(ignoreN == 2){
						old_old_choice = old_choice;
						old_choice = choice;
					}else if(ignoreN == 1){
						old_choice = choice;
					}
					
					
					curIter++;
					
				}
				
				


				if( curIter >= maxIter ){
					cout << "Reached max iterations. Saving Image File..." << endl;
					
					// Make the BYTE array, factor of 3 because it's RBG.
					unsigned char* pixels = new unsigned char[3 * width * height];

					glReadPixels(0, 0, width, height, GL_BGR, GL_UNSIGNED_BYTE, pixels);
					
					// Convert to FreeImage format & save to file
					FIBITMAP* image = FreeImage_ConvertFromRawBits(pixels, width, height, 3 * width, 24, 0x0000FF, 0xFF0000, 0x00FF00, false);
					FreeImage_Save(FIF_BMP, image, outputPath.c_str(), 0);

					// Free resources
					FreeImage_Unload(image);
					delete [] pixels;					
					return 0;
				}
				
				//~ amount += 0.001;
				//~ cout << "math >>" << sin(2.2) << endl;
				glfwSwapBuffers(window);
				glfwPollEvents();
			}
		}
	}
	return 0;
}
