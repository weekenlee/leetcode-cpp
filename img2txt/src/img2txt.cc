#include<leptonica/allheaders.h>
#include<tesseract/baseapi.h>
using namespace tesseract;

int main()
{
    char *outText;
    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    if (api->Init(NULL,"chi_sim")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
    }

    Pix *image = pixRead("check.jpg");
    api->SetImage(image);
    outText = api->GetUTF8Text();
    printf("%s", outText);
    api->End();
    delete []outText;
    pixDestroy(&image);
    return 0;
}
