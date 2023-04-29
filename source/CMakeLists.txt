add_executable(LabelMeshGen main.cxx)
target_link_libraries(LabelMeshGen ${ITK_LIBRARIES} ${VTK_LIBRARIES})