pipeline {
    agent {
      label 'jenkins-01'
    }
    stages {
        stage('Configure') {
            steps {
                dir('build') {
                    cmakeBuild buildDir: 'build', cmakeArgs: '-DENABLE_TESTING=ON', installation: 'InSearchPath', sourceDir: '..'
                }
            }
        }
        stage('Build') {
            steps {
                dir('build') {
                    cmakeBuild installation: 'InSearchPath', sourceDir: '..', steps: [[withCmake: true]]
                }
            }
        }
        stage('Test') {
            steps {
                dir('build') {
                    ctest arguments: '--no-compress-output -T Test', installation: 'InSearchPath'
                }
            }
            post {
                always {
                    xunit([CTest(deleteOutputFiles: true, failIfNotNew: true, pattern: 'build/Testing/**/*.xml', skipNoTestFiles: false, stopProcessingIfError: true)])
                    archiveArtifacts (
                        artifacts: 'build/Testing/**/*.xml',
                        fingerprint: true
                     )
                    deleteDir()
                }
            }
        }
    }
}
