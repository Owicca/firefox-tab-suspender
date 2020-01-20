#include <stdbool.h>
#include <stdint.h>
#include "../../data/data_sources/cache_data_source/cache_data_source.h"
#include "../../data/data_sources/settings_data_source/settings_data_source.h"
#include "../../providers/javascript_functions_provider/javascript_functions_provider.h"
#include "wasm_initialization_action.h"

static void run(const uint32_t* buffer, uint32_t bufferSize, void (*jsExpiredTabsWatcher)(void),
                void (*jsClearInterval)(void), void (*jsChromeTabsDiscard)(uint32_t, bool), void (*jsConsoleLog)(uint32_t)) {
  JavascriptFunctionsProvider.initialize(jsExpiredTabsWatcher, jsClearInterval, jsChromeTabsDiscard, jsConsoleLog);

  CacheDataSource.initialize();

  JavascriptFunctionsProvider.consoleLog(66660);
  JavascriptFunctionsProvider.consoleLog(buffer[0]);
  JavascriptFunctionsProvider.consoleLog(66661);
  JavascriptFunctionsProvider.consoleLog(buffer[1]);
  JavascriptFunctionsProvider.consoleLog(66662);
  JavascriptFunctionsProvider.consoleLog(buffer[2]);
  JavascriptFunctionsProvider.consoleLog(66663);
  JavascriptFunctionsProvider.consoleLog(buffer[3]);
  JavascriptFunctionsProvider.consoleLog(66664);
  JavascriptFunctionsProvider.consoleLog(buffer[4]);

  uint32_t timeToDiscard = buffer[0];
  bool neverSuspendPinned = (bool) buffer[1];
  bool neverSuspendUnsavedFormInput = (bool) buffer[2];
  bool neverSuspendPlayingAudio = (bool) buffer[3];
  bool desaturateFavicon = (bool) buffer[4];

  SettingsDataSource.initialize(timeToDiscard, neverSuspendPinned, neverSuspendUnsavedFormInput,
                                neverSuspendPlayingAudio, desaturateFavicon);
}

wasm_initialization_action_namespace const WasmInitializationAction = { run };
