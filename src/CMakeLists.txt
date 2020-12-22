################################################################################
#                                                                              #
# Copyright (C) 2019 Fondazione Istitito Italiano di Tecnologia (IIT)          #
# All Rights Reserved.                                                         #
#                                                                              #
################################################################################

# @author Luca Tricerri <luca.tricerri@iit.it>

project(fixapp)

set(FixAppSrc     main.cpp
                          
                        )

set(FixAppHdr    
                           
                       )

add_executable(${PROJECT_NAME} ${FixAppSrc} ${FixAppHdr} )

target_link_libraries(${PROJECT_NAME}  ${Common_LIBRARIES}
                                       pugixml::pugixml
                                       )

# install
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
