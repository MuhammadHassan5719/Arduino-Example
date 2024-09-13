/* Generated by Edge Impulse
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#ifndef _EI_CLASSIFIER_MODEL_METADATA_H_
#define _EI_CLASSIFIER_MODEL_METADATA_H_

#include <stdint.h>

#define EI_CLASSIFIER_NONE                       255
#define EI_CLASSIFIER_UTENSOR                    1
#define EI_CLASSIFIER_TFLITE                     2
#define EI_CLASSIFIER_CUBEAI                     3
#define EI_CLASSIFIER_TFLITE_FULL                4
#define EI_CLASSIFIER_TENSAIFLOW                 5
#define EI_CLASSIFIER_TENSORRT                   6

#define EI_CLASSIFIER_SENSOR_UNKNOWN             -1
#define EI_CLASSIFIER_SENSOR_MICROPHONE          1
#define EI_CLASSIFIER_SENSOR_ACCELEROMETER       2
#define EI_CLASSIFIER_SENSOR_CAMERA              3

// These must match the enum values in TensorFlow Lite's "TfLiteType"
#define EI_CLASSIFIER_DATATYPE_FLOAT32           1
#define EI_CLASSIFIER_DATATYPE_INT8              9

#define EI_CLASSIFIER_PROJECT_ID                 28056
#define EI_CLASSIFIER_PROJECT_OWNER              "Louis Moreau"
#define EI_CLASSIFIER_PROJECT_NAME               "Car Detection"
#define EI_CLASSIFIER_PROJECT_DEPLOY_VERSION     10
#define EI_CLASSIFIER_NN_INPUT_FRAME_SIZE        27648
#define EI_CLASSIFIER_RAW_SAMPLE_COUNT           9216
#define EI_CLASSIFIER_RAW_SAMPLES_PER_FRAME      1
#define EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE       (EI_CLASSIFIER_RAW_SAMPLE_COUNT * EI_CLASSIFIER_RAW_SAMPLES_PER_FRAME)
#define EI_CLASSIFIER_INPUT_WIDTH                96
#define EI_CLASSIFIER_INPUT_HEIGHT               96
#define EI_CLASSIFIER_INPUT_FRAMES               1
#define EI_CLASSIFIER_INTERVAL_MS                1
#define EI_CLASSIFIER_LABEL_COUNT                2
#define EI_CLASSIFIER_HAS_ANOMALY                0
#define EI_CLASSIFIER_FREQUENCY                  0
#define EI_CLASSIFIER_USE_QUANTIZED_DSP_BLOCK    0


#define EI_CLASSIFIER_OBJECT_DETECTION           0


#define EI_CLASSIFIER_TFLITE_ARENA_SIZE          63059
#define EI_CLASSIFIER_TFLITE_INPUT_DATATYPE      EI_CLASSIFIER_DATATYPE_INT8
#define EI_CLASSIFIER_TFLITE_INPUT_QUANTIZED     1
#define EI_CLASSIFIER_TFLITE_INPUT_SCALE         0.003921568859368563
#define EI_CLASSIFIER_TFLITE_INPUT_ZEROPOINT     -128
#define EI_CLASSIFIER_TFLITE_OUTPUT_DATATYPE     EI_CLASSIFIER_DATATYPE_INT8
#define EI_CLASSIFIER_TFLITE_OUTPUT_QUANTIZED    1
#define EI_CLASSIFIER_TFLITE_OUTPUT_SCALE        0.00390625
#define EI_CLASSIFIER_TFLITE_OUTPUT_ZEROPOINT    -128
#define EI_CLASSIFIER_INFERENCING_ENGINE         EI_CLASSIFIER_TFLITE
#define EI_CLASSIFIER_COMPILED                   1
#define EI_CLASSIFIER_HAS_TFLITE_OPS_RESOLVER    1

#define EI_CLASSIFIER_SENSOR                     EI_CLASSIFIER_SENSOR_CAMERA
#ifndef EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW
#define EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW    4
#endif // EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW
#define EI_CLASSIFIER_SLICE_SIZE                 (EI_CLASSIFIER_RAW_SAMPLE_COUNT / EI_CLASSIFIER_SLICES_PER_MODEL_WINDOW)

#if EI_CLASSIFIER_INFERENCING_ENGINE == EI_CLASSIFIER_TFLITE && EI_CLASSIFIER_USE_FULL_TFLITE == 1
#undef EI_CLASSIFIER_INFERENCING_ENGINE
#undef EI_CLASSIFIER_HAS_TFLITE_OPS_RESOLVER
#define EI_CLASSIFIER_INFERENCING_ENGINE          EI_CLASSIFIER_TFLITE_FULL
#define EI_CLASSIFIER_HAS_TFLITE_OPS_RESOLVER     0
#if EI_CLASSIFIER_COMPILED == 1
#error "Cannot use full TensorFlow Lite with EON"
#endif
#endif // EI_CLASSIFIER_INFERENCING_ENGINE == EI_CLASSIFIER_TFLITE && EI_CLASSIFIER_USE_FULL_TFLITE == 1

const char* ei_classifier_inferencing_categories[] = { "cars", "unknown" };

typedef struct {
    uint16_t implementation_version;
    int axes;
    float scale_axes;
    bool average;
    bool minimum;
    bool maximum;
    bool rms;
    bool stdev;
    bool skewness;
    bool kurtosis;
} ei_dsp_config_flatten_t;

typedef struct {
    uint16_t implementation_version;
    int axes;
    const char * channels;
} ei_dsp_config_image_t;

typedef struct {
    uint16_t implementation_version;
    int axes;
    int num_cepstral;
    float frame_length;
    float frame_stride;
    int num_filters;
    int fft_length;
    int win_size;
    int low_frequency;
    int high_frequency;
    float pre_cof;
    int pre_shift;
} ei_dsp_config_mfcc_t;

typedef struct {
    uint16_t implementation_version;
    int axes;
    float frame_length;
    float frame_stride;
    int num_filters;
    int fft_length;
    int low_frequency;
    int high_frequency;
    int win_size;
    int noise_floor_db;
} ei_dsp_config_mfe_t;

typedef struct {
    uint16_t implementation_version;
    int axes;
    float scale_axes;
} ei_dsp_config_raw_t;

typedef struct {
    uint16_t implementation_version;
    int axes;
    float scale_axes;
    const char * filter_type;
    float filter_cutoff;
    int filter_order;
    int fft_length;
    int spectral_peaks_count;
    float spectral_peaks_threshold;
    const char * spectral_power_edges;
} ei_dsp_config_spectral_analysis_t;

typedef struct {
    uint16_t implementation_version;
    int axes;
    float frame_length;
    float frame_stride;
    int fft_length;
    int noise_floor_db;
    bool show_axes;
} ei_dsp_config_spectrogram_t;

typedef struct {
    uint16_t implementation_version;
    int axes;
    float frame_length;
    float frame_stride;
    int num_filters;
    int fft_length;
    int low_frequency;
    int high_frequency;
    float pre_cof;
} ei_dsp_config_audio_syntiant_t;

uint8_t ei_dsp_config_3_axes[] = { 0 };
const uint32_t ei_dsp_config_3_axes_size = 1;
ei_dsp_config_image_t ei_dsp_config_3 = {
    1,
    1,
    "RGB"
};

#endif // _EI_CLASSIFIER_MODEL_METADATA_H_
