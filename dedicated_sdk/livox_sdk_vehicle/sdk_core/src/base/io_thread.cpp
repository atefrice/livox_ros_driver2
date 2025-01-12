//
// The MIT License (MIT)
//
// Copyright (c) 2019 Livox. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include "io_thread.h"

namespace livox {
namespace vehicle {

void IOThread::Join() {
  ThreadBase::Join();
}

void IOThread::ThreadFunc() {
  if (!loop_) {
    return;
  }

  while (!IsQuit()) {
    loop_->Loop();
  }
}

bool IOThread::Init(bool enable_timer, bool enable_wake) {
  if (!ThreadBase::Init()) {
    return false;
  }

  loop_ = std::make_shared<IOLoop>(enable_timer, enable_wake);
  return loop_->Init();
}

void IOThread::Uninit() {
  if (loop_) {
    loop_->Uninit();
  }
  ThreadBase::Uninit();
}

}
}  // namespace livox
