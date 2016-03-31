#include <CkHttp.h>
#include<stdio.h>
#include<iostream>

using namespace std;
int main(int argc, char *argv[])
    {
    
    if(argc < 2)
	{
		cout << "Missing filename. Correct usage : ./s3_upload.cpp <filename>" <<endl;
		return 1;
	}

    CkHttp http;

    bool success;
    success = http.UnlockComponent("Anything for 30-day trial");
    if (success != true) {
        cout<<http.lastErrorText()<<endl;
        return 1;
    }

    //  Insert your access key here:
    http.put_AwsAccessKey("AKIAJAWVDVKHXABLRYJQ");

    //  Insert your secret key here:
    http.put_AwsSecretKey("Ec5NUKDBvcbUB2XapEMjANMNxPq/c0ZRIC3ImSXl");

    const char * bucketName;
    bucketName = "ketan-cloudcomputing";

    const char * objectName;
    objectName = argv[1];

    const char * localFilePath;
    localFilePath = argv[1];

    const char * contentType;
    contentType = "text/html";

    success = http.S3_UploadFile(localFilePath,contentType,bucketName,objectName);

    if (success != true) {
        cout << http.lastErrorText();
    }
    else {
        cout << "File "<<argv[1]<<" has been uploaded to Amazon S3 bucket "<<bucketName << endl;
    }

return 0;
}
