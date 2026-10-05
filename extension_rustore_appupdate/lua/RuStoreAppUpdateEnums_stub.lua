-- Stub for Defold Editor (autocomplete + diagnostics).
-- Runtime global RuStoreAppUpdateEnums is created by native extension (C++).
-- Do not require this file.

---@class RuStoreAppUpdateEnums_InstallErrorCode
---@field ERROR_UNKNOWN integer
---@field ERROR_DOWNLOAD integer
---@field ERROR_BLOCKED integer
---@field ERROR_INVALID_APK integer
---@field ERROR_CONFLICT integer
---@field ERROR_STORAGE integer
---@field ERROR_INCOMPATIBLE integer
---@field ERROR_APP_NOT_OWNED integer
---@field ERROR_INTERNAL_ERROR integer
---@field ERROR_ABORTED integer
---@field ERROR_APK_NOT_FOUND integer
---@field ERROR_EXTERNAL_SOURCE_DENIED integer
---@field ERROR_ACTIVITY_SEND_INTENT integer
---@field ERROR_ACTIVITY_UNKNOWN integer

---@class RuStoreAppUpdateEnums_InstallStatus
---@field UNKNOWN integer
---@field DOWNLOADED integer
---@field DOWNLOADING integer
---@field FAILED integer
---@field INSTALLING integer
---@field PENDING integer

---@class RuStoreAppUpdateEnums_UpdateAvailability
---@field UNKNOWN integer
---@field UPDATE_NOT_AVAILABLE integer
---@field UPDATE_AVAILABLE integer
---@field DEVELOPER_TRIGGERED_UPDATE_IN_PROGRESS integer

---@class RuStoreAppUpdateEnums_UpdateFlowResult
---@field RESULT_OK integer
---@field RESULT_CANCELED integer
---@field ACTIVITY_NOT_FOUND integer

---@class RuStoreAppUpdateEnums_Root
---@field InstallErrorCode RuStoreAppUpdateEnums_InstallErrorCode
---@field InstallStatus RuStoreAppUpdateEnums_InstallStatus
---@field UpdateAvailability RuStoreAppUpdateEnums_UpdateAvailability
---@field UpdateFlowResult RuStoreAppUpdateEnums_UpdateFlowResult

---@type RuStoreAppUpdateEnums_Root
RuStoreAppUpdateEnums = RuStoreAppUpdateEnums
