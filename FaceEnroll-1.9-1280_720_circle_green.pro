######################################################################
# Automatically generated by qmake (2.01a) Wed Mar 10 13:53:08 2021
######################################################################

TEMPLATE = app
TARGET = FaceEnroll-1.9-1280_720_circle_green_server
OBJECTS_DIR = intermediate/obj
MOC_DIR = intermediate/moc
RCC_DIR = intermediate
UI_DIR  =forms



LIBS += -L ./lib  -lopencv_highgui  -lopencv_gpu  -lopencv_contrib -lopencv_objdetect -lopencv_core -lopencv_calib3d -lopencv_features2d -lopencv_flann  -lopencv_imgproc -lopencv_legacy -lopencv_ml -lopencv_nonfree -lopencv_photo -lopencv_stitching -lopencv_ts -lopencv_video -lopencv_videostab
LIBS += -L./Camlib/ -lv4l2 -lv4l2util -lv4lconvert -ljpeg -lgl11pos -lpcsclite -lkf311
LIBS += -L ./lib/qtlibdlib.a

DEPENDPATH += . \
              include \
              opencv \
              opencv2 \
              src \
              opencv2/calib3d \
              opencv2/contrib \
              opencv2/core \
              opencv2/features2d \
              opencv2/flann \
              opencv2/gpu \
              opencv2/highgui \
              opencv2/imgproc \
              opencv2/legacy \
              opencv2/ml \
              opencv2/nonfree \
              opencv2/objdetect \
              opencv2/photo \
              opencv2/stitching \
              opencv2/ts \
              opencv2/video \
              opencv2/videostab \
              opencv2/stitching/detail
INCLUDEPATH += . \
               include \
               opencv \
               opencv2/core \
               opencv2/imgproc \
               opencv2/video \
               opencv2/features2d \
               opencv2/flann \
               opencv2/calib3d \
               opencv2/objdetect \
               opencv2/legacy \
               opencv2/highgui \
               opencv2/nonfree

# Input
HEADERS += include/capture-win.h \
           include/compheader.h \
           include/FaceAuthentication.h \
           include/facedetect.h \
           include/general-tab.h \
           include/gl11.h \
           include/landmarkdetection.h \
           include/lib_sample.h \
           include/lib_sample_global.h \
           include/libv4l2.h \
           include/libv4l2util.h \
           include/libv4lconvert.h \
           include/posix_qextserialport.h \
           include/qextserialbase.h \
           include/qv4l2.h \
           include/showthread.h \
           include/thread.h \
           include/ui_mainwindow.h \
           include/v4l2-api.h \
           include/videodev2.h \
           include/videodevice.h \
           opencv/cv.h \
           opencv/cv.hpp \
           opencv/cvaux.h \
           opencv/cvaux.hpp \
           opencv/cvwimage.h \
           opencv/cxcore.h \
           opencv/cxcore.hpp \
           opencv/cxeigen.hpp \
           opencv/cxmisc.h \
           opencv/highgui.h \
           opencv/ml.h \
           opencv2/opencv.hpp \
           opencv2/opencv_modules.hpp \
           opencv2/calib3d/calib3d.hpp \
           opencv2/contrib/contrib.hpp \
           opencv2/contrib/detection_based_tracker.hpp \
           opencv2/contrib/hybridtracker.hpp \
           opencv2/contrib/retina.hpp \
           opencv2/core/core.hpp \
           opencv2/core/core_c.h \
           opencv2/core/devmem2d.hpp \
           opencv2/core/eigen.hpp \
           opencv2/core/gpumat.hpp \
           opencv2/core/internal.hpp \
           opencv2/core/mat.hpp \
           opencv2/core/opengl_interop.hpp \
           opencv2/core/operations.hpp \
           opencv2/core/types_c.h \
           opencv2/core/version.hpp \
           opencv2/core/wimage.hpp \
           opencv2/features2d/features2d.hpp \
           opencv2/flann/all_indices.h \
           opencv2/flann/allocator.h \
           opencv2/flann/any.h \
           opencv2/flann/autotuned_index.h \
           opencv2/flann/composite_index.h \
           opencv2/flann/config.h \
           opencv2/flann/defines.h \
           opencv2/flann/dist.h \
           opencv2/flann/dummy.h \
           opencv2/flann/dynamic_bitset.h \
           opencv2/flann/flann.hpp \
           opencv2/flann/flann_base.hpp \
           opencv2/flann/general.h \
           opencv2/flann/ground_truth.h \
           opencv2/flann/hdf5.h \
           opencv2/flann/heap.h \
           opencv2/flann/hierarchical_clustering_index.h \
           opencv2/flann/index_testing.h \
           opencv2/flann/kdtree_index.h \
           opencv2/flann/kdtree_single_index.h \
           opencv2/flann/kmeans_index.h \
           opencv2/flann/linear_index.h \
           opencv2/flann/logger.h \
           opencv2/flann/lsh_index.h \
           opencv2/flann/lsh_table.h \
           opencv2/flann/matrix.h \
           opencv2/flann/miniflann.hpp \
           opencv2/flann/nn_index.h \
           opencv2/flann/object_factory.h \
           opencv2/flann/params.h \
           opencv2/flann/random.h \
           opencv2/flann/result_set.h \
           opencv2/flann/sampling.h \
           opencv2/flann/saving.h \
           opencv2/flann/simplex_downhill.h \
           opencv2/flann/timer.h \
           opencv2/gpu/devmem2d.hpp \
           opencv2/gpu/gpu.hpp \
           opencv2/gpu/gpumat.hpp \
           opencv2/gpu/stream_accessor.hpp \
           opencv2/highgui/highgui.hpp \
           opencv2/highgui/highgui_c.h \
           opencv2/imgproc/imgproc.hpp \
           opencv2/imgproc/imgproc_c.h \
           opencv2/imgproc/types_c.h \
           opencv2/legacy/blobtrack.hpp \
           opencv2/legacy/compat.hpp \
           opencv2/legacy/legacy.hpp \
           opencv2/legacy/streams.hpp \
           opencv2/ml/ml.hpp \
           opencv2/nonfree/features2d.hpp \
           opencv2/nonfree/nonfree.hpp \
           opencv2/objdetect/objdetect.hpp \
           opencv2/photo/photo.hpp \
           opencv2/photo/photo_c.h \
           opencv2/stitching/stitcher.hpp \
           opencv2/stitching/warpers.hpp \
           opencv2/ts/ts.hpp \
           opencv2/ts/ts_gtest.h \
           opencv2/ts/ts_perf.hpp \
           opencv2/video/background_segm.hpp \
           opencv2/video/tracking.hpp \
           opencv2/video/video.hpp \
           opencv2/videostab/deblurring.hpp \
           opencv2/videostab/fast_marching.hpp \
           opencv2/videostab/fast_marching_inl.hpp \
           opencv2/videostab/frame_source.hpp \
           opencv2/videostab/global_motion.hpp \
           opencv2/videostab/inpainting.hpp \
           opencv2/videostab/log.hpp \
           opencv2/videostab/motion_stabilizing.hpp \
           opencv2/videostab/optical_flow.hpp \
           opencv2/videostab/stabilizer.hpp \
           opencv2/videostab/videostab.hpp \
           opencv2/stitching/detail/autocalib.hpp \
           opencv2/stitching/detail/blenders.hpp \
           opencv2/stitching/detail/camera.hpp \
           opencv2/stitching/detail/exposure_compensate.hpp \
           opencv2/stitching/detail/matchers.hpp \
           opencv2/stitching/detail/motion_estimators.hpp \
           opencv2/stitching/detail/seam_finders.hpp \
           opencv2/stitching/detail/util.hpp \
           opencv2/stitching/detail/util_inl.hpp \
           opencv2/stitching/detail/warpers.hpp \
           opencv2/stitching/detail/warpers_inl.hpp
FORMS += FaceAuthentication.ui
SOURCES += src/capture-win.cpp \
           src/ctrl-tab.cpp \
           src/FaceAuthentication.cpp \
           src/facedetect.cpp \
           src/general-tab.cpp \
           src/landmarkdetection.cpp \
           src/main.cpp \
           src/qextserialbase.cpp \
           src/qv4l2.cpp \
           src/showthread.cpp \
           src/thread.cpp \
           src/v4l2-api.cpp \
           src/videodevice.cpp
RESOURCES += resource.qrc
