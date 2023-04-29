#include <iostream>
#include <string>
#include <itkImage.h>
#include <itkSmartPointer.h>
#include <itkImageFileReader.h>


int main (int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cerr << "Usage: LabelMeshGen image_input.nii.gz label_config.json mesh_output.vtk" << std::endl;
    return EXIT_FAILURE;
  }
  std::string fnImageIn = argv[1];
  std::string fnConfig = argv[2];
  std::string fnMeshOut = argv[3];

  typedef uint16_t LabelType;
  typedef itk::Image<LabelType, 3> Image3DType;
  typedef itk::ImageFileReader<Image3DType> Image3DReaderType;

  auto reader = Image3DReaderType::New();
  reader->SetFileName(fnImageIn.c_str());
  reader->Update();
  auto imageIn = reader->GetOutput();

  std::cout << imageIn << std::endl;
  imageIn->Print(std::cout);

  return EXIT_SUCCESS;
}