using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "lib/webview.h"
#include "lib/tinyfiledialogs.c"
#include "lib/escape.h"
static char * filter[2] = { "*.md", "*.txt" };
string lastFile;
static void cb(struct webview *w, const char *arg) {
	string raw = arg;
	if (raw == "open"){
		auto filename = tinyfd_openFileDialog("Open a markdown file", "", 2, filter, NULL, 0);
		string fileText;
		if (!(filename == NULL)){
			ifstream t(filename);
			string str((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());
			fileText = escape_json(str);
			lastFile = filename;
			webview_set_title(w, ("ajmark - " + lastFile).c_str());
		}
		string built = "app.setText(\""+fileText+"\")";
		webview_eval(w, built.c_str());
	}
	else if(raw == "new"){ 
		lastFile = "";
		webview_set_title(w, "ajmark");
	}
	else if(!lastFile.empty()){
		ofstream out(lastFile);
		out << raw;
	}
	else{ 
		auto save = tinyfd_saveFileDialog("Save markdown file", "filename.md", 2, filter, NULL);
		if (!(save == NULL)){
			ofstream out(save);
			out << raw;
			lastFile = save;
			webview_set_title(w, ("ajmark - " + lastFile).c_str());
	}
		}
};
int main (){
	string cwd = getcwd(NULL, 0);
	string built = "file:///"+cwd+"/index.html";
	struct webview webview = {};
	webview.title = "ajmark";
	webview.url = built.c_str();
	webview.width = 800;
	webview.height = 600;
	webview.resizable = 1;
	webview.debug = 0;
	webview.external_invoke_cb = cb;
	webview_init(&webview);
	while ((webview_loop(&webview, 1) == 0)){
	}
};