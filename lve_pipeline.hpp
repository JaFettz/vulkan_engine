#pragma once

#include "lve_device.hpp"

#include <string>
#include <vector>

namespace lve {

struct PipeLineConfigInfo {
  VkViewport viewport;
  VkRect2D scissor;
  VkPipelineViewportStateCreateInfo viewportInfo;
  VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
  VkPipelineRasterizationStateCreateInfo rasterizationInfo;
  VkPipelineMultisampleStateCreateInfo multisampleInfo;
  VkPipelineColorBlendAttachmentState colorBlendAttachment;
  VkPipelineColorBlendStateCreateInfo colorBlendInfo;
  VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
  VkPipelineLayout pipelineLayout = nullptr;
  VkRenderPass renderPass = nullptr;
  uint32_t subpass = 0;
};

class LvePipeline {
public:
  LvePipeline(LveDevice &device, const std::string &vertFilePath,
              const std::string &fragFilePath,
              const PipeLineConfigInfo &configInfo);

  ~LvePipeline();

  LvePipeline(const LvePipeline &) = delete;
  void operator=(const LvePipeline &) = delete;

  static PipeLineConfigInfo defaultPipelineConfigInfo(uint32_t width,
                                                      uint32_t height);

private:
  static std::vector<char> readFile(const std::string &filepath);

  void createGraphicsPipeline(const std::string &vertFilePath,
                              const std::string &fragFilePath,
                              const PipeLineConfigInfo &configInfo);

  void createShaderModule(const std::vector<char> &code,
                          VkShaderModule *shaderModule);

  LveDevice &lveDevice;
  VkPipeline graphicsPipeline;
  VkShaderModule verShaderModule;
  VkShaderModule fragShaderModule;
};
} // namespace lve
